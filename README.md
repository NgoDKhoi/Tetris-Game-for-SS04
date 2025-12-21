# Đồ án Tetris nhóm 8 - SS004.Q12
## Giới thiệu
Đây là một đồ án game Tetris môn kỹ năng nghề nghiệp gồm 5 thành viên:
- `Huỳnh Cao Kỳ` - 24520923 (nhóm trưởng)
- `Ngô Đình Khôi` - 24520860
- `Nguyễn Đình Anh Khôi` - 24520862
- `Trần Minh Khôi` - 24520871
- `Lê Văn Lộc` - 24520982
![alt text](Image/Background_Tetris.png)

## Một số link khác của nhóm:
`Overleaf`: https://www.overleaf.com/read/mctjygkthkkv#66e8f5  
`Trello`: https://trello.com/b/8489k7jo/nhom-knnn  
`Slack`: https://app.slack.com/client/T09DLM2RRNX/C09V8HS9XMW

## Giới thiệu về game Tetris
Tetris là một trò chơi điện tử thuộc thể loại xếp gạch (puzzle game) kinh
điển, được sáng tạo bởi nhà thiết kế phần mềm người Liên Xô/Nga Alexey
Pajitnov vào năm 1984. Tên gọi "Tetris" được ghép từ tiền tố Hy Lạp tetra
(nghĩa là “bốn”) – ám chỉ bốn ô vuông tạo nên mỗi khối, và tennis – môn
thể thao yêu thích của Pajitnov.

Tetris không chỉ là một trò chơi đơn thuần; nó đã trở thành một biểu
tượng văn hóa đại chúng toàn cầu, nổi tiếng nhờ thiết kế tối giản nhưng
chứa đựng chiều sâu chiến thuật đáng kinh ngạc. Trong gần 40 năm, Tetris
đã xuất hiện trên hầu hết mọi nền tảng giải trí (từ máy tính, console, điện
thoại cho đến các thiết bị gia dụng) và vẫn giữ vững sức hấp dẫn vượt thời
gian

### Tác động của Tetris
- Là một trong những trò chơi bán chạy nhất mọi thời đại với hơn
495 triệu bản.
- Được xếp vào danh sách những trò chơi có tầm ảnh hưởng lớn nhất
trong lịch sử.
- Được nhiều nghiên cứu chứng minh mang lại tác động tích cực đến:
khả năng phản xạ, trí nhớ, tư duy không gian.

## Gameplay cơ bản
Trong Tetris, người chơi điều khiển các khối hình học gọi là Tetromino
– mỗi khối được cấu tạo từ bốn ô vuông. Các khối rơi từ phía trên màn
hình xuống, và người chơi phải xoay, di chuyển và sắp xếp chúng sao cho tạo
thành một hàng ngang đầy đủ. Khi một hàng được lấp kín hoàn toàn, hàng
đó sẽ biến mất và người chơi được cộng điểm.
Trò chơi kết thúc khi các khối bị chồng lên đến đỉnh màn hình, khiến
người chơi không còn không gian để đặt Tetromino mới.

### Các loại Tetromino trong Tetris
- I – Khối dài thẳng.
- O – Khối vuông.
- T – Dạng chữ T.
- L – Dạng chữ L.
- J – Dạng chữ J (L ngược).
- S – Khối ziczac hướng trái.
- Z – Khối ziczac hướng phải.
  
Để đạt điểm cao, người chơi cần áp dụng các chiến thuật ngắn hạn
(vị trí đặt từng khối rơi) kết hợp với chiến thuật dài hạn (quy hoạch mặt
phẳng, chừa chỗ tạo Tetris – phá 4 hàng cùng lúc). Khả năng phản xạ, tư
duy không gian và sự linh hoạt khi xử lý tình huống là yếu tố then chốt trong
gameplay của Tetris.

### Hướng dẫn chơi game
| Phím | Chức năng |
|-----|----------|
| **W** ⬆️ | Xoay khối |
| **A** ⬅️ | Di chuyển sang trái |
| **D** ➡️ | Di chuyển sang phải |
| **S** ⬇️ | Rơi nhanh |
| **P** ⏸️ | Tạm dừng |
| **Q** <img src="Image/icons_exit.png" width="20" style="vertical-align:middle;"/> | Thoát game |

## Quá trình làm việc
- 8/12/2025:
  + `Ngô Đình Khôi (24520860)`
    * Ở nhánh *main*, code phần khởi tạo board Tetris mảng 2D, hiển thị bảng trống.
    * Tạo nhánh *TuDongRoi*, viết tính năng tự động rơi cho khối.
  + `Huỳnh Cao Kỳ (24520923)`:
    * Tạo nhánh *TaoBlock*, code phần tạo Block I, O và thêm block vào board.
    * Ở nhánh *TuDongRoi*, code thêm tính năng tự động rơi.
- 10/12/2025:
  + `Ngô Đình Khôi (24520860)`
    * Tạo nhánh *ThemDiChuyen*, thêm tính năng di chuyển trái phải và Fix lỗi.
- 11/12/2025
  + `Huỳnh Cao Kỳ (24520923)`:
    * Ở nhánh *ThemDiChuyen*, viết tăng tốc độ rơi bằng 's' và Sửa lỗi thiếu các block.
  + `Nguyễn Đình Anh Khôi (24520862):
    * Ở nhánh *ThemDiChuyen*, viết thêm reset new block.
- 12/12/2025
  + `Ngô Đình Khôi (24520862)`
    * Tạo nhánh *XuLyVaCham*, viết thêm phần Create: removeline() & isLineFull(), ClearFullLine và ÁP dụng clearFullLines() vào gameplay và vẽ lại.
- 13/12/2025
  + `Lê Văn Lộc (24520982)`:
    * Tạo nhanh *ThemBlock*, viết tính năng thêm block khi block trước đó rơi xuống.
  + `Huỳnh Cao Kỳ (24520923)`:
    * Ở nhánh *XuLyVaCham*, viết thêm hiệu nhấp nháy sau khi xóa được 1 hàng và thêm bộ tính điểm.
- 15/12/2025
  + `Huỳnh Cao Kỳ (24520923)`:
    * Ở nhánh *XuLyVaCham*, Fix di chuyển cho các khối, đổi lại vị trí của form code.
  + `Trần Minh Khôi (24520871):
    * Tạo nhánh *ThaoTacXoay*, viết tính năng cho phép xoay khối theo y muốn.
- 16/12/2025
  + `Trần Minh Khôi (24520871):
    * Tạo nhánh *PauseGame*, viết tính năng cho Pause Game khi muốn.
- 17/12/2025
  + `Trần Minh Khôi (24520871):
    * Ở nhánh *PauseGame*, Fix bug tính năng.
- 20/12/2025
  + `Huỳnh Cao Kỳ (24520923)`:
    * Ở nhánh *XuLyVaCham*, viết di chuyển khung xuống dưới.
- 21/12/2025
  + `Huỳnh Cao Kỳ (24520923)`:
    * Ở nhánh *XuLyVaCham*, viết thêm bảng hướng dẫn chơi game
  

    
