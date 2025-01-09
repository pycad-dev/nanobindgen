/**
 * Test
 *
 */
class Test
{
  public:
    /**
     * Complex parameters
     *
     * @param a a
     * @param b b
     * @param c c
     * @nb
     */
    void nontrivial_params(std::vector<std::string> &a, double *b = nullptr,
                           std::vector<int> &c = std::vector<int>());

    /**
     * An overloaded function
     *
     * @param a First param
     * @nb
     */
    void overload(double &a);

    /**
     * An overloaded function
     *
     * @param a Alternate param
     * @nb
     */
    void overload(int a);

    /**
     * A magic method
     * @nb name: __magic__
     */
    void magic();

    static int static_method();
};

/**
 * Second class
 *
 */
class Test2
{
  public:
    /**
     * Get the name object
     *
     * @return The name
     * @nb prop_r: name
     */
    std::string get_name();

    /**
     * Set the name object
     *
     * @param name The name
     * @nb prop_w: name
     */
    void set_name(std::string name);

    /**
     * Read-only property
     * @nb prop_r: prop
     */
    void get_prop();
};

/**
 * Don't bind this function you silly program
 *
 */
void dontbind();

/**
 * A free function
 *
 * @param a Hello
 * @param b Bye
 * @return Fye
 * @nb
 */
void free(int a, double b);

/**
 * A simple return type
 *
 * @return Simple return type
 * @nb
 */
int free_return_simple();
