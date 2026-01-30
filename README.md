# QTTimer

<div align="center">
  <img src="https://skillicons.dev/icons?i=cpp" height="40" alt="cplusplus logo"  />
  <img width="12" />
  <img src="https://skillicons.dev/icons?i=qt" height="40" alt="visualstudio logo"  />
</div>


## Таймер и лог

### Условие

Создать небольшое приложение Qt с интерфейсом:

Интерфейс:
- Кнопка **"Start"**  
Кнопка **"Stop"**
- Многострочное поле (QTextEdit), куда выводится лог
- Надпись с текущим временем таймера

**Логика:**

При нажатии **Start** запускается таймер, который каждые 1 секунду пишет в лог сообщение вроде:

```
Tick 1
Tick 2
Tick 3
```

1. Обновляет отображаемое время.
2. При нажатии **Stop** таймер останавливается.

## Алгоритмическая задача (уровень Medium, LeetCode-style)

### Условие

Задача: [LeetCode #3 — Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

### Решение

#### static array (0ms, 11MB)

```
class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        if (s.empty()) return 0;

        std::size_t res = 0;
        
        constexpr auto alphabetSize = 128;
        std::array<std::size_t, alphabetSize> lastPos;
        lastPos.fill( s.size() );
        
        std::size_t left = 0;
        for (std::size_t right = 0; right < s.size(); ++right) {
            const auto uc = static_cast<unsigned char>(s[right]);

            if (lastPos[uc] >= left && lastPos[uc] != s.size()) {
                left = lastPos[uc] + 1;
            }

            lastPos[uc] = right;
            res = std::max(res, right - left + 1);
        }

        return res;
    }
};
```

#### hashmap (7ms, 11.8MB)

```
class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        if (s.empty()) return 0;

        std::size_t res = 0;
        
        std::unordered_map<char, std::size_t> lastPos;
        
        std::size_t left = 0;
        for (std::size_t right = 0; right < s.size(); ++right) {
            const auto c = s[right];

            if (lastPos.contains(c) && lastPos[c] >= left) {
                left = lastPos[c] + 1;
            }

            lastPos[c] = right;
            res = std::max(res, right - left + 1);
        }

        return res;
    }
};
```
