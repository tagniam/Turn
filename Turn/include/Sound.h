
#include <string>

class SoundMaker {
public:
	SoundMaker(void);
	void PlayPrimaryAttack(void);
	void PlaySecondaryAttack(void);
	void PlayHeal(void);
protected:
	void SetPrimaryAttackFileName(const std::string &filename);
	void SetPrimarySecondaryAttackFileName(const std::string &filename);
	void SetHealFileName(const std::string &filename);
private:
	std::string attackFileName;
	std::string attack2FileName;
	std::string healFileName;
};