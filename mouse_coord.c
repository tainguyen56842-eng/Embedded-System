#include <stdio.h>
#include <ncurses.h>

int main() {
    // Khởi tạo màn hình ncurses
    initscr();              
    noecho();               // Không hiển thị ký tự người dùng gõ lên màn hình
    cbreak();               // Tắt chế độ chờ Enter (nhận phím ngay lập tức)
    keypad(stdscr, TRUE);   // Bật hỗ trợ phím đặc biệt (phím mũi tên, chuột,...)

    // Kích hoạt tính năng bắt sự kiện chuột (cho phép nhận toàn bộ sự kiện chuyển động/click)
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    printw("=== CHUONG TRINH DOC TOA DO CHUOT TRÊN CONSOLE ===\n");
    printw("Hay di chuyen hoac click chuot trong cua so nay.\n");
    printw("Nhan phim 'q' de thoat.\n\n");
    refresh();

    MEVENT event; // Biến lưu thông tin sự kiện chuột
    int ch;

    while ((ch = getch()) != 'q') {
        if (ch == KEY_MOUSE) {
            if (getmouse(&event) == OK) {
                // event.x là hoành độ (cột), event.y là tung độ (dòng)
                mvprintw(5, 0, "Toa do chuot -> X: %d / Y: %d    ", event.x, event.y);
                refresh();
            }
        }
    }

    // Kết thúc chế độ ncurses, trả lại màn hình terminal bình thường
    endwin();
    return 0;
}
