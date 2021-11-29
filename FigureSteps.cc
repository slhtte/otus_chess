#include "FigureSteps.h"

std::vector<std::string> KingSteps::Run(std::vector<std::string> &data)
{
    using UL = unsigned long;
    
    std::vector<std::string> result(2);
    UL first = 1;
    UL K = first << std::stoi(data[0]);
    
    UL noA = 0xfefefefefefefefe;
    UL noH = 0x7f7f7f7f7f7f7f7f;
    UL Ka = K & noA;
    UL Kh = K & noH;
    
    UL M = (Ka << 7) | (K << 8) | (Kh << 9) |
           (Ka >> 1) |            (Kh << 1) |
           (Ka >> 9) | (K >> 8) | (Kh >> 7) ;
    
    
    result[0] = std::to_string(popcnt(M));
    result[1] = std::to_string(M);
    
    return result;
}

std::vector<std::string> HorseSteps::Run(std::vector<std::string> &data)
{
    using UL = unsigned long;
    
    std::vector<std::string> result(2);
    UL first = 1;
    UL H = first << std::stoi(data[0]);
    
    UL noA = 0xfefefefefefefefe;
    UL noAB = 0xfcfcfcfcfcfcfcfc;
    UL noH = 0x7f7f7f7f7f7f7f7f;
    UL noGH = 0x3f3f3f3f3f3f3f3f;
    UL Ha = H & noA;
    UL Hh = H & noH;
    UL Hab = H & noAB;
    UL Hgh = H & noGH;

    UL M =                (Ha << 15) | (Hh << 17) |
            (Hab << 6) |                           (Hgh << 10) |
            (Hab >> 10) |                          (Hgh >> 6)  |
                          (Ha >> 17) | (Hh >> 15);
    
    
    result[0] = std::to_string(popcnt(M));
    result[1] = std::to_string(M);
    
    return result;
}

std::vector<std::string> CastleSteps::Run(std::vector<std::string> &data)
{
    using UL = unsigned long;
    
    std::vector<std::string> result(2);
    UL C = (UL)1 << std::stoi(data[0]);
    UL tmp = C;
    unsigned int count_w = 0;
    unsigned int count_h = 0;
    
    static const UL line_1 = 0xff;
    static const UL A = 0x101010101010101;
    static const unsigned int WIDTH = 8;
    
    while (!(tmp & A))
    {
        tmp >>= 1; 
        ++count_w;
    }

    tmp = C;

    while(!(tmp & line_1))
    {
        tmp >>= WIDTH;
        ++count_h;
    }

    UL M = (A << count_w) ^ (line_1 << (WIDTH * count_h));
    
    
    result[0] = std::to_string(popcnt(M));
    result[1] = std::to_string(M);
    
    return result;
}

std::vector<std::string> BishopSteps::Run(std::vector<std::string> &data)
{
    using UL = unsigned long;
    
    std::vector<std::string> result(2);
    UL B = (UL)1 << std::stoi(data[0]);
    UL tmp1 = B;
    UL tmp2 = B;
    
    static const UL corner_A1 = 0x1010101010101ff;
    static const UL corner_H8 = 0xff80808080808080;
    static const UL corner_A8 = 0xff01010101010101;
    static const UL corner_H1 = 0x80808080808080ff;
    
    while (!(tmp1 & corner_A1))
    {
        tmp1 >>= 9; 
    }

    while (!(tmp1 & corner_H8))
    {
        tmp1 |= (tmp1 << 9); 
    }
    
    while (!(tmp2 & corner_H1))
    {
        tmp2 >>= 7; 
    }

    while (!(tmp2 & corner_A8))
    {
        tmp2 |= (tmp2 << 7); 
    }

    UL M = (tmp1 | tmp2) ^ B;
    
    
    result[0] = std::to_string(popcnt(M));
    result[1] = std::to_string(M);
    
    return result;
}

std::vector<std::string> QueenSteps::Run(std::vector<std::string> &data)
{
    using UL = unsigned long;
    
    std::vector<std::string> result(2);
    UL Q = (UL)1 << std::stoi(data[0]);
    UL tmp1 = Q;
    UL tmp2 = Q;
    
    
    static const UL corner_A1 = 0x1010101010101ff;
    static const UL corner_H8 = 0xff80808080808080;
    static const UL corner_A8 = 0xff01010101010101;
    static const UL corner_H1 = 0x80808080808080ff;
    
    while (!(tmp1 & corner_A1))
    {
        tmp1 >>= 9; 
    }

    while (!(tmp1 & corner_H8))
    {
        tmp1 |= (tmp1 << 9); 
    }
    
    while (!(tmp2 & corner_H1))
    {
        tmp2 >>= 7; 
    }

    while (!(tmp2 & corner_A8))
    {
        tmp2 |= (tmp2 << 7); 
    }

    UL like_bishop = tmp1 | tmp2;

    unsigned int count_w = 0;
    unsigned int count_h = 0;
    UL tmp3 = Q;
    static const UL line_1 = 0xff;
    static const UL A = 0x101010101010101;
    static const unsigned int WIDTH = 8;
    
    while (!(tmp3 & A))
    {
        tmp3 >>= 1; 
        ++count_w;
    }

    tmp3 = Q;

    while(!(tmp3 & line_1))
    {
        tmp3 >>= WIDTH;
        ++count_h;
    }

    UL like_castle = (A << count_w) | (line_1 << (WIDTH * count_h));

    UL M = like_bishop ^ like_castle;
    
    
    result[0] = std::to_string(popcnt(M));
    result[1] = std::to_string(M);
    
    return result;
}