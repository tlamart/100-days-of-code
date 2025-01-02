#include <cs50.h>
#include <stdio.h>

int get_int_1_to_8(void);
void draw_pyramid(int height);
void draw_floor(int floor, int height);
void print_face_a(int floor, int height);
void print_face_b(int floor, int height);

int main(void)
{
    int height = get_int_1_to_8();
    draw_pyramid(height);
}

int get_int_1_to_8(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n > 8);
    return n;
}

void draw_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        draw_floor(i, height);
    }
}

void draw_floor(int floor, int height)
{
    print_face_a(floor, height);
    printf("  ");
    print_face_b(floor, height);
    printf("\n");
}

void print_face_a(int floor, int height)
{
    for (int i = 0; i < height; i++)
    {
        if (i < height - floor - 1)
        {
            printf(" ");
        }
        else
        {
            printf("#");
        }
    }
}

void print_face_b(int floor, int height)
{
    for (int i = 0; i <= floor; i++)
    {
        printf("#");
    }
}
