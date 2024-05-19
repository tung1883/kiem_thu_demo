#!/bin/bash
export PATH=/home/tung1883/tung1883/infer-linux64-v1.1.0/bin/:$PATH

# Flag to track if the list has been printed before
list_printed=false

analyze() {
    make clean 
    infer capture --reactive -- make 
    infer analyze --reactive --cost --bufferoverrun
    cp infer-out/report.json static-check/reports/report-$(git rev-parse --abbrev-ref HEAD).json
}

print_main() {
    if [ -f "./static-check/reports/report-$(git rev-parse --abbrev-ref HEAD).json" ]; then
        echo ""
        echo "------------------------------------------------ MAIN REPORT ------------------------------------------------"
        echo ""
        cat ./static-check/reports/report-$(git rev-parse --abbrev-ref HEAD).json | jq .
        
        echo ""
        echo "-------------------------------------------------------------------------------------------------------------"
        echo ""
    else
        echo "Main report does not not exist. Exiting..."
    fi
}

print_dif() {
    if [[ -f "./infer-out/differential/fixed.json" && -f "./infer-out/differential/introduced.json" && -f "./infer-out/differential/preexisting.json" ]]; then
        echo ""
        echo "------------------------------------------------ FIXED BUGS ------------------------------------------------"
        echo ""
        cat ./infer-out/differential/fixed.json | jq .
        
        echo ""
        echo "-------------------------------------------------------------------------------------------------------------"
        echo ""
        echo ""
        echo "------------------------------------------------ INTRODUCED BUGS ------------------------------------------------"
        echo ""
        cat ./infer-out/differential/introduced.json | jq .
        
        echo ""
        echo "-------------------------------------------------------------------------------------------------------------"
        echo ""
        echo ""
        echo "------------------------------------------------ PREEXISTING BUGS ------------------------------------------------"
        echo ""
        cat ./infer-out/differential/preexisting.json | jq .
        
        echo ""
        echo "-------------------------------------------------------------------------------------------------------------"
        echo ""
    else
        echo "Differential reports do not not exist. Exiting..."
    fi
}

while true; do
    if [ "$list_printed" = false ] || [ "$choice" = "L" ]; then
        echo "Commands:"
        echo "1. Analyze the current branch"
        echo "2. Compare to main branch"
        echo "3. Get the main report"
        echo "4. Get the cost report"
        echo "5. Get differential reports"
        echo "Q. Quit"
    fi

    # Read user input
    read -p "Enter your choice: " choice

    # Execute action based on user input
    case "$choice" in
        1) 
            echo "Analyze the current branch..."
            analyze

            ;;
        2) 
            echo "Compare to main branch..."

            # Go to feature branch if not there already
            echo "Checkout to the feature branch..."
            git checkout feature > /dev/null 2>&1

            # Get list of changed files
            echo "Get list of changed files..."
            git diff --name-only | grep -v 'infer-out/' > ./static-check/modified.txt

            ## First run: feature branch
            # Run infer on the feature branch
            echo "Analyze the feature branch..."

            analyze > /dev/null 2>&1
            

            ## Second run: main branch
            echo "Checkout to the main branch..."
            git checkout main > /dev/null 2>&1

            # Run capture in reactive mode so that previously-captured source files are kept if they are up-to-date
            echo "Analyze the main branch..."
            
            analyze > /dev/null 2>&1

            # Compare reports
            echo "Creating differential reports between the two branch..."
            infer reportdiff --report-current report-feature.json --report-previous infer-out/report.json
            print_dif

            ;;
        3) 
            print_main

            ;;
        4) 
            if [ -f "./infer-out/costs-report.json" ]; then
                echo ""
                echo "------------------------------------------------ COST REPORT ------------------------------------------------"
                echo ""
                cat ./infer-out/costs-report.json | jq -r '.[] | "Path: \(.loc.file) - Procedure: \(."procedure_name") - Cost: \(.exec_cost.hum.big_o)"' | awk '/^File/ {print; next} {print NR ". " $0}'
                
                echo ""
                echo "-------------------------------------------------------------------------------------------------------------"
                echo ""
            else
                echo "Cost report does not exist. Exiting..."
            fi
            
            ;;
        5) 
            print_dif
            
            ;;
        [lL]) 
            # Print the list
            echo "Select an action:"
            echo "1. Analyze the current branch"
            echo "2. Compare to main branch"
            echo "3. Get the cost report"
            echo "4. Get differential reports"
            echo "L. Print the list"
            echo "Q. Quit"
            list_printed=true
            ;;
        [qQ]) 
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please enter a valid option."
            ;;
    esac
done
