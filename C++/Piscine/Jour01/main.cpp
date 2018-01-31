#include <iostream>

int	main(int argc, char *argv[])
{
  int	i;

  i = 0;
  while (i < argc)
  {
    std::cout << argv[i] << std::endl;
    i++;
  }
  return (0);
}
