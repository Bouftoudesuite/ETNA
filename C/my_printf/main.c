int my_printf(char const *format, ...);

int main()
{
  my_printf("%d %% %d %c", 2, 3, 'a');
  return 0;
}
