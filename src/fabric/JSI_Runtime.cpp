#include "JSI_Runtime.h" //→ 헤더 파일을 포함 
#include <iostream> //→ C++에서 std::cout로 출력할 때 필요

// JavaScript에서 사용할 C++ 함수를 등록하는 함수
// functions[name] = func; → { "helloWorld": &myCppFunction } 이런 식으로 저장
void JSI_Runtime::registerFunction(const std::string& name, JSI_Function func) {
    functions[name] = func;
}

// JavaScript가 호출한 함수 실행
// 1. functions.find(name) != functions.end() → 함수가 존재하는지 확인
// 2. 존재 하는시 실행 functions[name](arg);
// 3. 없으면 "Function not found" 반환
std::string JSI_Runtime::callFunction(const std::string& name, const std::string& arg) {
    if (functions.find(name) != functions.end()) {
        return functions[name](arg);
    }
    return "Function not found";
}