#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class ExpressionTree {
private:
  class Node {
  public:
    string val;
    Node *left;
    Node *right;

    Node(string val) : val(val), left(nullptr), right(nullptr) {}
    Node() : val(""), left(nullptr), right(nullptr) {}
  };

  Node *root;

  void inorder(Node *s) {
    if (s != nullptr) {
      inorder(s->left);
      cout << s->val << " ";
      inorder(s->right);
    }
  }

  void preorder(Node *s) {
    if (s != nullptr) {
      cout << s->val << " ";
      preorder(s->left);
      preorder(s->right);
    }
  }

  void postorder(Node *s) {
    if (s != nullptr) {
      postorder(s->left);
      postorder(s->right);
      cout << s->val << " ";
    }
  }
  void setRootFromStack(stack<Node *> &exps) {
    if (!exps.empty()) {
      root = exps.top();
      exps.pop();
    } else {
      root = nullptr;
      cout << "Empty expression" << endl;
    }
  }

public:
  ExpressionTree(string exp) {
    if (exp.empty()) {
      cout << "Empty expression" << endl;
      root = nullptr;
      return;
    }

    stack<char> ops;
    stack<Node *> exps;

    int i = 0;

    bool isSingleOperand = true;
    for (char c : exp) {
      if (isOp(c)) {
        isSingleOperand = false;
        break;
      }
    }

    if (isSingleOperand) {
      root = new Node(exp);
      return;
    }
    while (i < exp.length()) {
      if (exp[i] == '(') {
        ops.push(exp[i]);
        i++;
      } else if (exp[i] == ')') {
        while (!ops.empty() && ops.top() != '(') {
          char tmp = ops.top();
          ops.pop();
          Node *s2 = exps.top();
          exps.pop();
          Node *s1 = exps.top();
          exps.pop();
          Node *s = new Node(string(1, tmp));
          s->left = s1;
          s->right = s2;
          cout << s->val << endl;
          exps.push(s);
        }
        if (!ops.empty() && ops.top() == '(')
          ops.pop();
        i++;
      } else if (!ops.empty() && isOp(exp[i]) &&
                 isPre(exp[i]) > isPre(ops.top())) {
        ops.push(exp[i]);
        i++;
      } else if (!ops.empty() && isOp(exp[i]) &&
                 isPre(exp[i]) <= isPre(ops.top())) {
        while (!ops.empty() && isPre(exp[i]) <= isPre(ops.top())) {
          char tmp = ops.top();
          ops.pop();
          Node *s2 = exps.top();
          exps.pop();
          Node *s1 = exps.top();
          exps.pop();
          Node *s = new Node(string(1, tmp));
          s->left = s1;
          s->right = s2;
          exps.push(s);
        }
        ops.push(exp[i]);
        i++;
      } else if (ops.empty() && isOp(exp[i])) {
        ops.push(exp[i]);
        i++;
      } else if (!isOp(exp[i])) {
        string num;
        while (i < exp.length() && (isdigit(exp[i]) || exp[i] == '.')) {
          num += exp[i];
          i++;
        }
        Node *s = new Node(num);
        exps.push(s);
      }
    }
    while (!ops.empty()) {
      char tmp = ops.top();
      ops.pop();
      Node *s2 = exps.top();
      exps.pop();
      Node *s1 = exps.top();
      exps.pop();
      Node *s = new Node(string(1, tmp));
      s->left = s1;
      s->right = s2;
      exps.push(s);
    }
    setRootFromStack(exps);
  }

  int isPre(char ch) {
    if (ch == '*' || ch == '/')
      return 1;
    else if (ch == '+' || ch == '-')
      return 0;
    else if (ch == '(')
      return -1;
    return 0;
  }

  bool isOp(char ch) {
    return ch == '*' || ch == '-' || ch == '+' || ch == '/' || ch == '.';
  }

  double getValue(string ch, double a, double b) {
    if (ch == "/") {
      return a / b;
    } else if (ch == "*") {
      return a * b;
    } else if (ch == "+") {
      return a + b;
    } else if (ch == "-") {
      return a - b;
    }
    return 0;
  }

  double getRes() {
    if (root == nullptr) {
      cout << "The tree is empty" << endl;
      return -1;
    }

    return getDfs(root);
  }

  double getDfs(Node *s) {
    if (s->left == nullptr && s->right == nullptr) {
      return stod(s->val);
    } else {
      double leftVal = getDfs(s->left);
      double rightVal = getDfs(s->right);
      return getValue(s->val, leftVal, rightVal);
    }
  }

  void levelOrder() {
    if (root == nullptr) {
      cout << "The tree is empty" << endl;
      return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *p = q.front();
      q.pop();
      cout << p->val << " ";
      if (p->left)
        q.push(p->left);
      if (p->right)
        q.push(p->right);
    }
    cout << endl;
  }

  void inorderTraversal() {
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
  }

  void preorderTraversal() {
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
  }

  void postorderTraversal() {
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
  }
  void inorder() { inorderTraversal(); }

  void postorder() { postorderTraversal(); }

  void preorder() { preorderTraversal(); }

  double evaluate() { return getRes(); }
};
int main() {
  string exp;
  cout << "Enter an expression: ";
  cin >> exp;

  ExpressionTree t1(exp);

  cout << "Level Order: ";
  t1.levelOrder();

  t1.inorder();
  t1.preorder();
  t1.postorder();

  cout << "Evaluate: " << t1.evaluate() << endl;

  return 0;
}
