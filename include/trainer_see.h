#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

#include "global.h"
#include "task.h"

bool8 CheckForTrainersWantingBattle(void);
bool8 CheckForTrainersPossiblyWantingBattle(TaskFunc follow);
void MovementAction_RevealTrainer_RunTrainerSeeFuncList(struct ObjectEvent *var);
u8 FldEff_ExclamationMarkIcon1(void);
u8 FldEff_DoubleExclMarkIcon(void);
u8 FldEff_XIcon(void);
u8 FldEff_SmileyFaceIcon(void);
u8 FldEff_QuestionMarkIcon(void);

#endif //GUARD_TRAINER_SEE_H
