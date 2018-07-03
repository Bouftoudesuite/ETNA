#include <my.h>
#include <sys/stat.h>
#include <sys/types.h>

static void print_type(struct stat *buffer)
{
    if (S_ISDIR(buffer->st_mode))
        my_putchar('d');
    else if (S_ISCHR(buffer->st_mode))
        my_putchar('c');
    else if (S_ISLNK(buffer->st_mode))
        my_putchar('l');
    else if (S_ISBLK(buffer->st_mode))
        my_putchar('b');
    else
        my_putchar('-');
}

static void print_usr_right(struct stat *buffer)
{
    my_putchar((buffer->st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((buffer->st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((buffer->st_mode & S_IXUSR) ? 'x' : '-');
}

static void print_grp_right(struct stat *buffer)
{
    my_putchar((buffer->st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((buffer->st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((buffer->st_mode & S_IXGRP) ? 'x' : '-');
}

static void print_oth_right(struct stat *buffer)
{
    my_putchar((buffer->st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((buffer->st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((buffer->st_mode & S_IXOTH) ? 'x' : '-');
}


void print_chmod(const char *path)
{
    struct stat buffer;

    if (lstat(path, &buffer) == -1)
    {
        my_putstr("./my_ls: error lstat");
        return ;
    }
    print_type(&buffer);
    print_usr_right(&buffer);
    print_grp_right(&buffer);
    print_oth_right(&buffer);
}
