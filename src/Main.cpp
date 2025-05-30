#include "Audio/AudioInput.h"

#include <thread>

#include "Gui/MainWindow.h"

#include <QApplication>
#include <iostream>


int main(int argc, char *argv[]) {

  AudioInput input1("input 1");
  AudioInput input2("input 2");
  AudioInput input3("input 3");

  std::thread t1 = std::thread(&AudioInput::run, &input1);
  std::thread t2 = std::thread(&AudioInput::run, &input2);
  std::thread t3 = std::thread(&AudioInput::run, &input3);

  t1.join();
  t2.join();
  t3.join();

  // QApplication a(argc, argv);
  // MainWindow w;
  // w.show();
  // return a.exec();

  return 0;
}
