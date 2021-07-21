#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>

size_t random_one(size_t a, size_t b)
{
    if (a >= b)
        return a;

    static std::random_device g_random_device;
    static std::mt19937 mt(g_random_device());
    std::uniform_int_distribution<size_t> gen(a, b);
    return gen(mt);
}

int main(int argc, char *argv[])
{
    // default params
    size_t min_num = 1;
    size_t max_num = 10;
    size_t total = 200;
    size_t question_per_page = 10;

    if (argc > 5 || argc == 2)
    {
        std::cout << "usage : ./homework min_num max_num question_per_page total" << std::endl;
        return 0;
    }

    if (argc >= 3)
    {
        min_num = std::strtoul(argv[1], nullptr, 10);
        max_num = std::strtoul(argv[2], nullptr, 10);
        if (argc >= 4)
        {
            question_per_page = std::strtoul(argv[3], nullptr, 10);
            if (argc == 5)
                total = std::strtoul(argv[4], nullptr, 10);
        }
    }

    std::cout << "---\nmarp: true\nsize: 4:3\npaginate: true\ntheme: default\n";

    for (size_t i = 0; i < total; ++i)
    {
        if (i % question_per_page == 0)
            std::cout << "---\n";
        std::cout << "- " << random_one(min_num, max_num) << " + " << random_one(min_num, max_num) << " =\n";
    }

    return 0;
}
