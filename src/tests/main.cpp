#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTestSuite
#include <boost/test/unit_test.hpp>

boost::unit_test::test_suite *init_unit_test_suite(int argc, char *argv[]) {
  std::cout << "Init unit test suite" << std::endl;
  std::cout << "argc: " << argc << std::endl;
  std::cout << "argv: " << argv << std::endl;
  boost::unit_test::framework::master_test_suite().p_name.value =
      "My Test Suite";
  return 0;
}