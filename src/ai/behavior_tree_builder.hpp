#ifndef BEHAVIOR_TREE_BUILDER_H
#define BEHAVIOR_TREE_BUILDER_H

#include <std_includes.hpp>
#include <ai/composite/composite.hpp>
#include <ai/leaf/action.hpp>
#include <ai/ai.hpp>

class BehaviorTreeBuilder {
private:
  BehaviorTree* _bt;
  ABehavior* _current;
public:
  BehaviorTreeBuilder();
  ~BehaviorTreeBuilder();

  // can be composites or decorators (root must be able to have child).
  BehaviorTreeBuilder* root(ABehavior* node);

  BehaviorTreeBuilder* composite(Composite* node);
  BehaviorTreeBuilder* decorator(Decorator* node);

  // Actions and Conditions won't change _current to itself.
  BehaviorTreeBuilder* action(Action* node);
  BehaviorTreeBuilder* condition(Condition* node);

  BehaviorTreeBuilder* end();

  BehaviorTree* create_tree();
};


#endif
