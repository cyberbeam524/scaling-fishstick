namespace A {    // Namespace declaration
  #ifndef ADD_H /* Include guard */
  #define ADD_H

  int add(int x, int y); /* An example function declaration */

  #endif // ADD_H

  class classA // Class definition
  {
    public:
        explicit classA();
        void run_A(); // Definition in classA.cpp

    private:
      int i;
  };

  struct rectangle {
    int length; // Member initialisation
    int breadth;
    int height;
  };
}