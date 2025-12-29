#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    int x, y;
} Point;
typedef struct{
    Point body[MAX_SNAKE_SIZE];
    int length;
    int direction;
} Snake;
void initGame(Snake *snake, Point *fruit);
void draw(Snake *snake, Point *fruit);
void moveSnake(Snake *snake, Point *fruit);
int main(){
    //initscr();
    //clear();
    //curs_set(0);
    //mvprintw(10,0,"h");
    //refresh();
    Snake python;
    Point apple;
    initGame(&python, &apple);
    draw(&python, &apple);
    moveSnake(&python, &apple);
    getch();
    //endwin();
    return 0;
}
void initGame(Snake *snake, Point *fruit){
    srand(time(0));
    initscr();
    curs_set(0);
    timeout(100);
    snake->length=5;
    snake->direction=KEY_RIGHT;
    for(int i=0;i<snake->length;i++){
        snake->body[i].x=10-i;
        snake->body[i].y=10;
    }
    fruit->x=rand()%COLS;
    fruit->y=rand()%LINES;
}
void draw(Snake *snake, Point *fruit){
    clear();
    mvprintw(fruit->y, fruit->x, "O");
    for(int i=0;i<snake->length;i++){
        if(i==0){
            mvprintw(snake->body[i].y, snake->body[i].x, "@");
        }
        else {
            mvprintw(snake->body[i].y, snake->body[i].x, "#");
        }
    }
    refresh();
}
void moveSnake(Snake *snake, Point *fruit){
    Point new_head=snake->body[0];
    new_head.x++;
    for(int i=snake->length;i>0;i--){
        snake->body[i]=snake->body[i-1];
    }
    snake->body[0]=new_head;
}