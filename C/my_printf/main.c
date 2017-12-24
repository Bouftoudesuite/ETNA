int my_printf(const char * restrict str, ...);

int main(int argc, char const *argv[])
{
    my_printf("Elle avait %d %c", 2, 'j');
    return 0;
}
