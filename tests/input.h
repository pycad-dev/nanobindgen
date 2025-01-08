/**
 * Test
 *
 */
class Test {
public:
  void trivial();

  void param(int a);





  void nontrivial_params(std::vector<std::string> &a, double *b = nullptr,
                         std::vector<int> &c = std::vector<int>());

  /**
   * An overloaded function
   *
   * @param a First param
   */
  void overload(double &a);


  /**
   * An overloaded function
   * 
   * @param a Alternate param
   */
  void overload(int a);

  static int static_method();
};

/**
 * Second class
 *
 */
class Test2 {
public:
  /**
   * Trivial function
   * 
   */
  void trivial();
};

/**
 * A free function
 *
 * @param a Hello
 * @param b Bye
 * @return Fye
 */
void free(int a, double b);


/**
 * A simple return type
 *
 * @return Simple return type
 */
int free_return_simple();
