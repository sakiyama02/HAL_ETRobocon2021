COPTS += -DMAKE_EV3
COPTS += -DMAKE_EV3
mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS += \

APPL_CXXOBJS += \
				Action.o\
				ArmAction.o\
				Curve.o\
				LineTrace.o\
				Straight.o\
				CarPosition.o\
				PidControl.o\
				Steering.o\
				TrapezoidControl.o\
				GaActionInfomation.o\
				GaCurveInfomation.o\
				GaPidInfomation.o\
				GaPositionCorrectionInfomation.o\
				PositionCorrection.o\
				Garage.o\
				ScenarioControl.o\
				SceneControl.o\
				SlalomBlacky.o\
				SlalomEebui.o\
				SlalomEifie.o\
				TimeAttack.o\
				ColorSensor.o\
				SensorManager.o\
				SonicSensor.o\
				SlBkActionInfomation.o\
				SlBkCurveInfomation.o\
				SlBkPidInfomation.o\
				SlBkPositionCorrectionInfomation.o\
				SlEbActionInfomation.o\
				SlEbCurveInfomation.o\
				SlEbPidInfomation.o\
				SlEbPositionCorrectionInfomation.o\
				SlEfActionInfomation.o\
				SlEfCurveInfomation.o\
				SlEfPidInfomation.o\
				SlEfPositionCorrectionInfomation.o\
				Motor.o\
				Steering.o\
				System.o\
				TiActionInfomation.o\
				TiCurveInfomation.o\
				TiPidInfomation.o\
				TiPositionCorrectionInfomation.o\

#
SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries

include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile
#include $(mkfile_path)/workspace/library/RyujiEv3/Makefile

endif 

# COPTS += -DMAKE_BT_DISABLE

APPL_DIRS +=\
	$(mkfile_path)workspace/src/Calculation\
	$(mkfile_path)workspace/src/CarData\
	$(mkfile_path)workspace/src/CarryBlockInformation\
	$(mkfile_path)workspace/src/CouseMastering\
	$(mkfile_path)workspace/src/Decision\
	$(mkfile_path)workspace/src/GarageInformation\
	$(mkfile_path)workspace/src/Information\
	$(mkfile_path)workspace/src/Logger\
	$(mkfile_path)workspace/src/PidControl\
	$(mkfile_path)workspace/src/Sensor\
	$(mkfile_path)workspace/src/SlalomInformation\
	$(mkfile_path)workspace/src/Steering\
	$(mkfile_path)workspace/src/System\
	$(mkfile_path)workspace/src/TimeAttackInformation\
	$(mkfile_path)workspace/src/File\
	$(mkfile_path)workspace/src/CourseData


INCLUDES +=\
	-I$(mkfile_path)workspace/include/Calculation\
	-I$(mkfile_path)workspace/include/CarData\
	-I$(mkfile_path)workspace/include/CarryBlockInformation\
	-I$(mkfile_path)workspace/include/CouseMastering\
	-I$(mkfile_path)workspace/include/Decision\
	-I$(mkfile_path)workspace/include/GarageInformation\
	-I$(mkfile_path)workspace/include/Information\
	-I$(mkfile_path)workspace/include/Logger\
	-I$(mkfile_path)workspace/include/PidControl\
	-I$(mkfile_path)workspace/include/Sensor\
	-I$(mkfile_path)workspace/include/SlalomInformation\
	-I$(mkfile_path)workspace/include/Steering\
	-I$(mkfile_path)workspace/include/System\
	-I$(mkfile_path)workspace/include/TimeAttackInformation


COPTS += -I$(ETROBO_HRP3_WORKSPACE)/etroboc_common
COPTS += -DMAKE_EV3
COPTS += -DMAKE_EV3
COPTS += -std=gnu++11
COPTS += -fno-threadsafe-statics
COPTS += -DMAKE_EV3
