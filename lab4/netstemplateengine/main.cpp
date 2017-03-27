//
// Created by patryk on 21.03.17.
//
#include "SimpleTemplateEngine.h"




int main(){
    nets::View view("Patryk jest {{cool}} and {{smart}}");
    const unordered_map<string, string> bat={{"cool","spoko"},{"smart","madry"}};
    std::cout<<view.Render(bat)<<std::endl;
    return 0;
}
