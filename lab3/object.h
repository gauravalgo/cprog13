#ifndef OBJECT_H
#define OBJECT_H

#include <string>

namespace lab3 {
  class Object {
    protected:
    public:
      int hp;
      int hunger;
      int weight;
      int change_level;

      int x, y;
      char sym;
      Object();
      Object(int, int);

      int getX();
      int getY();

      virtual std::string symbol();
      virtual short type_id(){return 0;};
      virtual std::string description();
      virtual std::string action_description() { return "looked at"; };

      void set_position(int x, int y);
      virtual bool passable()       { return false; }; // can we walk over it?
      virtual bool inventorable()   { return false; }; // can we pick it up?
      virtual bool actionable()     { return false; }; // does it have an action we might be able to perform?
      virtual bool can_do_action()  { return false; }; // can we perform the action? Or have we already pressed the buttin for example.

      virtual Object * perform_action() { return new Object(13,13); };

      virtual int get_hunger()  { return 0; };
      virtual int get_hp()      { return 0; };
      virtual int get_weight()  { return 0; };

      void get_stats(int &, int &, int &);
      
      void apply_object_to_object(Object * o);

      virtual Object * tick() {};

  };
}
#endif
