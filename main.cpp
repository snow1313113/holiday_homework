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

enum OP_TYPE
{
    OP_ADD = 0,
    OP_SUB = 1,
};

void gen_add(size_t min_num_, size_t max_num_)
{
    std::cout << "- " << random_one(min_num_, max_num_) << " + " << random_one(min_num_, max_num_) << " =\n";
}

void gen_sub(size_t min_num_, size_t max_num_)
{
    size_t first = random_one(min_num_, max_num_);
    std::cout << "- " << first << " - " << random_one(min_num_, first) << " =\n";
}

void gen_question(OP_TYPE type_, size_t min_num_, size_t max_num_)
{
    switch (type_)
    {
    case OP_ADD:
        {
            gen_add(min_num_, max_num_);
            break;
        }
    case OP_SUB:
        {
            gen_sub(min_num_, max_num_);
            break;
        }
    default:
        break;
    }
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

    std::vector<OP_TYPE> all_types;
    all_types.push_back(OP_ADD);
    all_types.push_back(OP_SUB);
    for (size_t i = 0; i < total; ++i)
    {
        if (i % question_per_page == 0)
            std::cout << "---\n";
        auto index = random_one(0, all_types.size());
        gen_question(all_types[index], min_num, max_num);
    }

    return 0;
}
