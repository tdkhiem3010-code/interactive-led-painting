# TRANH LED TƯƠNG TÁC THÔNG MINH SỬ DỤNG ARDUINO UNO

## 1. Giới thiệu dự án

Tranh LED tương tác thông minh là mô hình ứng dụng vi điều khiển Arduino Uno kết hợp với các cảm biến để tạo ra hệ thống tranh có khả năng thay đổi cảnh hiển thị theo điều kiện môi trường và sự tương tác của con người.

Hệ thống sử dụng cảm biến ánh sáng để nhận biết sự thay đổi của môi trường và cảm biến siêu âm HC-SR04 để phát hiện vật thể đến gần. Dựa trên dữ liệu thu thập được, Arduino điều khiển các kênh LED thông qua module MOSFET, từ đó chuyển đổi giữa các cảnh hiển thị khác nhau.

## 2. Mục tiêu dự án

- Xây dựng mô hình tranh LED có khả năng tương tác với môi trường.
- Ứng dụng Arduino Uno trong điều khiển hệ thống chiếu sáng.
- Kết hợp cảm biến ánh sáng và cảm biến siêu âm để nhận biết điều kiện hoạt động.
- Thiết kế hệ thống điều khiển nhiều cảnh hiển thị.
- Tìm hiểu và ứng dụng module MOSFET trong điều khiển LED.

## 3. Chức năng chính

Hệ thống có ba chế độ hiển thị:

| Chế độ | Điều kiện hoạt động | Cảnh hiển thị |
|---|---|---|
| Cảnh 1 | Trạng thái mặc định, môi trường đủ sáng | Cảnh mặt trăng |
| Cảnh 2 | Cường độ ánh sáng vượt ngưỡng tối | Cảnh bầu trời ban ngày |
| Cảnh 3 | Phát hiện vật thể trong phạm vi 30 cm liên tục 3 giây | Cảnh khinh khí cầu |

### Thứ tự ưu tiên

1. Cảnh khinh khí cầu: ưu tiên cao nhất khi phát hiện vật thể đến gần.
2. Cảnh bầu trời ban ngày: kích hoạt khi môi trường tối.
3. Cảnh mặt trăng: trạng thái mặc định.

## 4. Danh sách linh kiện

| STT | Linh kiện | Số lượng |
|---|---|---|
| 1 | Arduino Uno | 1 |
| 2 | Cảm biến ánh sáng | 1 |
| 3 | Cảm biến siêu âm HC-SR04 | 1 |
| 4 | Module MOSFET 4 kênh UO4 | 1 |
| 5 | Dải LED 5V | Theo thiết kế |
| 6 | Pin 18650 | Theo thiết kế |
| 7 | Mạch sạc Type-C | 1 |
| 8 | Mạch tăng áp 5V | 1 |

## 5. Nguyên lý hoạt động

Arduino Uno đóng vai trò là bộ điều khiển trung tâm, thực hiện việc đọc dữ liệu từ các cảm biến và xử lý điều kiện để lựa chọn cảnh hiển thị.

### 5.1. Cảm biến ánh sáng

Cảm biến ánh sáng được kết nối với chân analog A0 của Arduino Uno. Giá trị đo được sử dụng để xác định trạng thái ánh sáng của môi trường.

- Khi giá trị cảm biến không vượt quá ngưỡng 500: hệ thống duy trì cảnh 1.
- Khi giá trị cảm biến lớn hơn 500: hệ thống chuyển sang cảnh 2 nếu không có vật thể đến gần.

### 5.2. Cảm biến siêu âm HC-SR04

Cảm biến HC-SR04 được sử dụng để đo khoảng cách từ hệ thống đến vật thể.

- Khoảng cách được đo liên tục.
- Khi vật thể nằm trong phạm vi 30 cm liên tục trong 3 giây, hệ thống xác nhận điều kiện tương tác.
- Khi điều kiện được xác nhận, hệ thống chuyển sang cảnh 3.
- Khi vật thể rời khỏi phạm vi phát hiện, hệ thống trở về chế độ hoạt động theo cảm biến ánh sáng.

### 5.3. Điều khiển LED bằng module MOSFET

Module MOSFET 4 kênh UO4 được sử dụng để điều khiển các kênh LED 5V theo tín hiệu từ Arduino Uno.

Chương trình lựa chọn một trong ba kênh LED tương ứng với ba cảnh hiển thị của tranh.

## 6. Sơ đồ kết nối

| Thiết bị | Chân Arduino Uno |
|---|---|
| LED 1 | D5 |
| LED 2 | D6 |
| LED 3 | D9 |
| HC-SR04 – TRIG | D10 |
| HC-SR04 – ECHO | D11 |
| Cảm biến ánh sáng | A0 |

## 7. Cấu trúc chương trình

Chương trình được xây dựng bằng Arduino C/C++ và bao gồm các chức năng chính:

- `tatTatCaDen()`: Tắt toàn bộ các kênh LED.
- `doKhoangCach()`: Đo khoảng cách bằng cảm biến HC-SR04.
- `batDen()`: Lựa chọn và bật kênh LED tương ứng.
- `setup()`: Khởi tạo các chân kết nối và giao tiếp Serial.
- `loop()`: Đọc cảm biến, xử lý điều kiện và điều khiển cảnh hiển thị.

## 8. Cài đặt và sử dụng

1. Cài đặt Arduino IDE.
2. Kết nối Arduino Uno với máy tính.
3. Mở file `interactive_led_painting.ino` trong thư mục `src`.
4. Chọn đúng Board Arduino Uno và cổng COM.
5. Biên dịch chương trình và tải code lên Arduino.
6. Cấp nguồn cho hệ thống và kiểm tra hoạt động của các cảm biến.

## 9. Công nghệ sử dụng

- Vi điều khiển: Arduino Uno.
- Ngôn ngữ lập trình: Arduino C/C++.
- Cảm biến khoảng cách: HC-SR04.
- Cảm biến ánh sáng: Analog Light Sensor.
- Điều khiển LED: Module MOSFET 4 kênh.

## 10. Tác giả và đóng góp

Dự án được thực hiện với mục đích nghiên cứu và ứng dụng kiến thức về vi điều khiển, cảm biến và điều khiển thiết bị điện tử trong xây dựng mô hình tranh LED tương tác.