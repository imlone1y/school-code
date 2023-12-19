# Description

A binary expression tree is a specific kind of a binary tree used to represent expressions.

Binary expression tree - Wikipedia

Please implement the ExpressionTree class in the template.
```cpp
class ExpressionTree {
public:
  //constructure an Expression Tree using a string. The string representing an in-order expression contains operator =, -, *, /, parentheses, and number in floationg point.
  ExpressionTree(string exp);
  //Display the Expression Tree in in-order traverse.
  void inorder();
  //Display the Expression Tree in post-order traverse.
  void postorder();
  //Display the Expression Tree in pre-order traverse.
  void preorder();
  //Evaluate the expression and return the result.
  double evaluate();
};
```
