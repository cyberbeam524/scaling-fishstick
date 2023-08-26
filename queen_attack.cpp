#include "queen_attack.h"
#include <utility>
#include <cmath>
#include <iostream>
#include <stdexcept>
namespace queen_attack {

    chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black){

        if ( white.first < 0 || white.second < 0 || black.first < 0 || black.second < 0 || 
        white.first > 7 || white.second > 7 || black.first > 7 || black.second > 7)
            throw std::domain_error("Cannot be less than 1");
        this->whitePair = white;
        this->blackPair = black;

    }
    std::pair<int, int> chess_board::white() const {
        return this->whitePair;
    }

    std::pair<int, int> chess_board::black() const {
        return this->blackPair;
    }

    bool chess_board::can_attack() const {

        int first = this->white().first, second = this->white().second;
        int targetfirst = this->black().first, targetSecond = this->black().second;

        if (first == targetfirst || second == targetSecond) return true;

        while (first >= 0 and second >= 0){
            if (targetfirst == first && targetSecond == second) return true;
            first--;
            second--;
        }

        first = this->white().first, second = this->white().second;
        while (first <= 7 && second <= 7){
            if (targetfirst == first && targetSecond == second) return true;
            first++;
            second++;
        }

        first = this->white().first, second = this->white().second;
        while (first <= 7 && second <= 7 && first >= 0 && second >= 0){
            if (targetfirst == first && targetSecond == second) return true;
            first--;
            second++;
        }

        first = this->white().first, second = this->white().second;
        while (first <= 7 && second <= 7 && first >= 0 && second >= 0){
            if (targetfirst == first && targetSecond == second) return true;
            first++;
            second--;
        }

        return false;
    }

}  // namespace queen_attack


// alternate solution 1: 
// ??why use special key word 'operator'? what does it do here???
// #include "queen_attack.h"
// namespace queen_attack {
//     chess_board::chess_board(const Position& white, const Position& black)
//         : _whitePos(white), _blackPos(black)
//     {
//         if(white == black) throw std::domain_error{"Position must be distinct"};
//     }
//     Position chess_board::white() const
//     {
//         return _whitePos;
//     }
//     Position chess_board::black() const
//     {
//         return _blackPos;
//     }
//     bool chess_board::can_attack() const
//     {
//         bool samerow = _whitePos.first == _blackPos.first;
//         bool samecol = _whitePos.second == _blackPos.second;
//         bool samediag = abs(_whitePos.first - _blackPos.first) 
//                               == abs(_whitePos.second - _blackPos.second);
//         return (samerow || samecol || samediag);
//     }
//     chess_board::operator std::string() const
//     {
//         std::string board;
//         for(int i = 0; i<8; i++)
//         {
//             for(int j = 0; j<8; j++)
//             {
//                 if(i==_whitePos.first && j==_whitePos.second)
//                 {
//                     board += "W "; continue;
//                 }
//                 if(i==_blackPos.first && j==_blackPos.second)
//                 {
//                     board += "B "; continue;
//                 }
//                 board += "_ "; 
//             }
//             board.pop_back();
//             board += "\n";
//         }
//         return board;
//     }
// }  // namespace queen_attack



// alternate solution 2: 
// ???what does pragma once do here??
// #pragma once
// #include <cmath>
// #include <stdexcept>
// #include <string>
// #include <utility>
// namespace queen_attack {
// class chess_board {
// private:
//   std::pair<uint8_t, uint8_t> m_white;
//   std::pair<uint8_t, uint8_t> m_black;
// public:
//   chess_board() : m_white({0, 3}), m_black({7, 3}) {}
//   chess_board(std::pair<uint8_t, uint8_t> white,
//               std::pair<uint8_t, uint8_t> black)
//       : m_white(white), m_black(black) {
//     if (white == black)
//       throw std::domain_error("Queens positions must be distinct.");
//   }
//   std::pair<uint8_t, uint8_t> white() const { return this->m_white; }
//   std::pair<uint8_t, uint8_t> black() const { return this->m_black; }
//   bool can_attack() const {
//     if (this->m_white.first == this->m_black.first) {
//       return true;
//     } else if (this->m_white.second == this->m_black.second) {
//       return true;
//     } else if (abs(this->m_white.first - this->m_black.first) ==
//                abs(this->m_white.second - this->m_black.second)) {
//       return true;
//     }
//     return false;
//   }
//   operator std::string() const {
//     std::string board = "";
//     for (uint8_t i = 0; i < 8; ++i) {
//       for (uint8_t j = 0; j < 8; ++j) {
//         if (i == this->m_white.first && j == this->m_white.second) {
//           board += "W";
//         } else if (i == this->m_black.first && j == this->m_black.second) {
//           board += "B";
//         } else {
//           board += "_";
//         }
//         board += j == 7 ? "\n" : " ";
//       }
//     }
//     return board;
//   }
// };
// } // namespace queen_attack