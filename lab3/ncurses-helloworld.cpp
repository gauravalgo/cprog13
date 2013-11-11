#include <ncurses.h>
#include <map>

typedef void (*MenuActionPtrType) ( void );
typedef std::map<char, MenuActionPtrType> action_map;

int RUNNING = true;

class Player {
  int x, y;
  
  public:

    Player() {
      x = 10;
      y = 10;
    }

    void move_up() {
      x--;
    }

    void move_down() {
      x++;
    }

    void move_right() {
      y++;
    }

    void move_left() {
      y--;
    }

    int getX() {
      return x;
    }

    int getY() {
      return y;
    }
};

Player p;

void move_self_up( void ) {
  p.move_up();
}
void move_self_down( void ) {
  p.move_down();
}

void move_self_right( void ) {
  p.move_right();
}

void move_self_left( void ) {
  p.move_left();
}

void action_quit( void ) {
  printw("Shuttin down");

  RUNNING = false;
}

void print_map() {
  erase();
  mvprintw(p.getX(), p.getY(), "X");
}

int main() {
  action_map actions;

  actions.insert(std::make_pair<char, MenuActionPtrType>('w', &move_self_up));
  actions.insert(std::make_pair<char, MenuActionPtrType>('d', &move_self_right));
  actions.insert(std::make_pair<char, MenuActionPtrType>('s', &move_self_down));
  actions.insert(std::make_pair<char, MenuActionPtrType>('a', &move_self_left));
  actions.insert(std::make_pair<char, MenuActionPtrType>('q', &action_quit));
  initscr();
  int c;
  mvprintw(p.getX(), p.getY(), "X");
  noecho();
  curs_set(0);

  while(RUNNING) {

    c = getch();
    // mvprintw(x, y, " ");
    // refresh();
    // if (c == 'w') { x--; }
    // if (c == 'd') { y++; }
    // if (c == 's') { x++; }
    // if (c == 'a') { y--; }

    // mvprintw(x, y, "X");
    action_map::const_iterator start = actions.find(c);
    if (start != actions.end()){
      // Not found
      ((*start).second) ();
    }

    print_map();
    
    refresh();

  }
  endwin();
  return 0;
}
