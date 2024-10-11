#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

struct Ball {
  string color;
  double radius;
};

struct Queue {
  Ball balls[MAX_SIZE];
  int front;
  int rear;
};

void initQueue(Queue& q) {
  q.front = -1;
  q.rear = -1;
}

bool isEmpty(const Queue& q) {
  return (q.front == -1);
}

bool isFull(const Queue& q) {
  return (q.rear == MAX_SIZE - 1);
}

void enqueue(Queue& q, const Ball& ball) {
  if (isFull(q)) {
    cout << "Queue is full" << endl;
    return;
  }

  if (isEmpty(q)) {
    q.front = 0;
  }

  q.rear = q.rear + 1;
  q.balls[q.rear] = ball;
}

void dequeue(Queue& q) {
  if (isEmpty(q)) {
    cout << "Queue is empty" << endl;
    return;
  }

  if (q.front == q.rear) {
    q.front = -1;
    q.rear = -1;
  } else {
    q.front++;
  }
}

Ball front(const Queue& q) {
  if (isEmpty(q)) {
    cout << "Queue is empty" << endl;
    return Ball();
  }
  return q.balls[q.front];
}

void printQueue(const Queue& q) {
  if (isEmpty(q)) {
    cout << "Empty queue." << endl;
    return;
  }

  for (int i = q.front; i <= q.rear; i++) {
    cout << "Color: " << q.balls[i].color << ", Radius: " << q.balls[i].radius << endl;
  }
}

bool isInQueue(const Queue& q, const Ball& ball) {
  for (int i = q.front; i <= q.rear; i++) {
    if (q.balls[i].color == ball.color && q.balls[i].radius == ball.radius) {
      return true;
    }
  }
  return false;
}

int main() {
  Queue myQueue;
  initQueue(myQueue);

  // Input several elements from user and put them in the queue
  int numBalls;
  cout << "Enter the number of balls to enqueue: ";
  cin >> numBalls;

  for (int i = 0; i < numBalls; ++i) {
    Ball newBall;
    cout << "Enter color for ball " << i + 1 << ": ";
    cin >> newBall.color;
    cout << "Enter radius for ball " << i + 1 << ": ";
    cin >> newBall.radius;
    enqueue(myQueue, newBall);
  }

  cout << "Front element: " << endl;
  Ball frontBall = front(myQueue);
  cout << "Color: " << frontBall.color << ", Radius: " << frontBall.radius << endl;

  dequeue(myQueue);
  cout << "After deque, Front: " << endl;
  frontBall = front(myQueue);
  cout << "Color: " << frontBall.color << ", Radius: " << frontBall.radius << endl;

  Ball ballToCheck;
  cout << "Enter color of ball to check: ";
  cin >> ballToCheck.color;
  cout << "Enter radius of ball to check: ";
  cin >> ballToCheck.radius;

  if (isInQueue(myQueue, ballToCheck)) {
    cout << "Ball is in the queue." << endl;
  } else {
    cout << "Ball is not in the queue." << endl;
  }

  cout << "Queue elements:" << endl;
  printQueue(myQueue);

  return 0;
}
