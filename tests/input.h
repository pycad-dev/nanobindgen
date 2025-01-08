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

  void overload(int a);

  void overload(double a);

  /**
   * Hi
   *
   * @param a Hello
   */
  void overload(double &a);

  static int static_method();
};

/**
 * Test2
 *
 */
class Test2 {
public:
  /**
   * Hive
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
 * Hello
 *
 * @param Bye Heat death of the universe
 */
void free(char c);

/**
 * Bye
 *
 * @return int
 */
int free2();
