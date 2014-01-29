#ifndef VICTORY_H
#define VICTORY_H

#include "inventorable.h"
#include <string>

namespace lab3 {
  class Victory : public Inventorable {
    protected:
    public:
      Victory();
      Victory(int x, int y);

      virtual short type_id() { return 10; }
      virtual std::string symbol() { return "V"; }
      virtual std::string description() { return "Victory token"; }
      virtual std::string action_description() { return "can quit anytime. You won. Its"; }
      virtual bool can_do_action() { return true; };

      virtual Object * perform_action();

      virtual int get_hp()      { return 10000; };
      virtual int get_hunger()  { return 3000; };
      virtual int get_weight()  { return 1; };
    };
}
#endif
