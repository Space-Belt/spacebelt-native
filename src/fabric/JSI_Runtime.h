
#pragma once //→ 중복 포함 방지 (헤더파일을 여러 번 포함해도 문제 없게 해줌)
#include <string> //→ 문자열을 사용하기 위해 필요
#include <unordered_map> //→ 함수 이름과 함수를 저장할 해시맵 (빠른 검색)
#include <functional> //→ C++ 함수 포인터(콜백) 사용을 위해 필요

class JSI_Runtime {
    public:
        using JSI_Function = std::function<std::string(const std::string&)>;

        void registerFunction(const std::string& name, JSI_Function func);
        std::string callFunction(const std::string& name, const std::string& arg);

    private:
        std::unordered_map<std::string, JSI_Function> functions;
};
