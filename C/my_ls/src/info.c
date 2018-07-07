#include <grp.h>
#include <info.h>
#include <my.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

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


void print_info(const char *path, t_list_flags *list_flags)
{
    char *time;
    struct stat buffer;

    (!get_flags('L', list_flags)) ? lstat(path, &buffer) : stat(path, &buffer);
    print_type(&buffer);
    print_usr_right(&buffer);
    print_grp_right(&buffer);
    print_oth_right(&buffer);
    my_putchar('\t');
    my_putnbr(buffer.st_nlink);
    my_putchar('\t');
    my_putstr(getpwuid(buffer.st_uid)->pw_name);
    my_putchar('\t');
    my_putstr(getgrgid(buffer.st_gid)->gr_name);
    my_putchar('\t');
    my_putnbr((unsigned int)buffer.st_size);
    my_putchar('\t');
    time = my_strrdup(ctime(&buffer.st_mtime), 4);
    time[my_strlen(time) - 9] = '\0';
    my_putstr(time);
    free(time);
}
