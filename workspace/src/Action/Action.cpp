

#include "../../include/Action/Action.h"

Action::Action(){}
Action::~Action(){}

int8 Action::run(int32 speed,PIDData pid_data = {0.0f,0.0f,0.0f,0.0f},
    float angle = 0.0f,CurveData curve_data = {0.0f,(CurveType)0}){

        return SYS_OK;

}