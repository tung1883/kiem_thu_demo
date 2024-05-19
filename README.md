Demo công cụ Infer
- Infer là một công cụ kiểm thử tĩnh và sẽ rất hữu ích trong việc tự động hóa quá trình phát hiện bug
- Trong bản demo này, chúng em thử cài đặt cho Infer để nó có thể phát hiện bug trong quá trình phát triển, cũng như tạo ra các bản report báo cáo cho developer
- Các công việc cụ thể bọn em làm như sau: 
1. Chúng em viết ra 1 bản script để chạy Infer. Ta chỉ cần việc chạy file script và ấn các số từ 1 -> 5 để lựa chọn các hành động của Infer như: phân tích branch hiện tại, so sánh với branch main, xem các bản report.
2. Tạo branch mới và thêm phần lỗi bị sai vào code để chạy thử Infer. Việc này cũng giống như mình gặp phải bug trong quá trình phát triển. Qua đó, mình thấy được Infer có thể giúp gì trong quá trình này