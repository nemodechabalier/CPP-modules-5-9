#include "ShrubberyCreationForm.hpp"

/* ............................................ORTHODOX CANONICAL FORM ............................................*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default_name", 145, 137) {
	_target = "default";
	std::cout << "ShrubberyCreationForm: default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, const std::string& target) : AForm(name, 145, 137) {
	_target = target;
	std::cout << "ShrubberyCreationForm: custom constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
	_target = other._target;
	std::cout << "ShrubberyCreationForm: copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm: default destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		_target = other._target;
	}
	std::cout << "ShrubberyCreationForm: assigment operator called" << std::endl;
	return *this;
}

/* ............................................ GETRER - SETTER ...................................................*/



/* ............................................ FUNCTIONS .........................................................*/

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) {
		std::cout << "Error ShrubberyCreationForm : " << getName() << " is not signed" << std::endl;
		return;
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
		return;
	}
	std::string filename = _target + ".txt";
	std::ofstream outputFile((filename).c_str());
	if (!outputFile) {
		std::cerr << "error outfile" << std::endl;
		return;
	}
	outputFile << "                             A\n"
		"                            / \\\n"
		"                           J   L\n"
		"                     ------'   `------\n"
		"                      `.           .'\n"
		"                        `.       .'\n"
		"                         /       \\\n"
		"                        J   .'.   L\n"
		"                        |.' | |`. |\n"
		"                        '   | |//`\n"
		"                       .-.-. _ _ _  |\n"
		"                      /| | |(/|||||_|\n"
		"                      _| | |/-'`'`'/|\n"
		"                     / \\/|   o  + __.- /(\n"
		"                    |  '|/| -|/(||||(_V_)\n"
		"                    `._.| |/_/_)`-'' ///_<\n"
		"                        >///\\\\\\\\\\//==<<<=\n"
		"                      _ >>>\\\\\\\\\\>//<__<<<-'\n"
		"                     / `-._>>>.-'   |<<\n"
		"                    J     _.))     /<<<<\n"
		"                v   |  .-'' |/__   |<<<||_\n"
		"             \\\\\\||| `-> _/ / \\  `-<<<<<<*** **\n"
		"           \\\\\\**|||| /    /><<\\    \\<<<********\n"
		"             >>**////    /<>>>>`.   |****** <<_\\_\\\n"
		"              >>***/_  .'>>><>>><\\  |*****<<<|_|_|\n"
		"           .-' >***>>|/>//>><\\\\**|/\\|***<<<<<|_|_|\n"
		"           \\.-' \\***<<<>>///\\\\\\******<<>><>>*****\\\\\\\\\\\\-.-.-<<<\n"
		"            \\-'_.J--.<<<<>><<****>>///(\\|\\)|(//<<<,\n"
		"           (   )|(-'  (>>><<****<\\\\)_.><<<<-\n"
		"          .-`-'_)\\-.--.\\>>><*****//||>(\\ (\\\\_.\\<<<< .-\n"
		"         .' _.-'()\\`.**>>//****<<<>><<`-``-``-`<<.-' _\n"
		"     .--'_.'>>>><>>`.\\***(`._.-.<<<<<<(_____``<.'_.-' |<\n"
		"    /-'   >><<>>>>>//<>>>/|\\ |  /<<>><|     `-._/      L\n"
		"           ->>.<>><>>>>>/|| \\|.'|<<>\\\\|  .-----'|._    |\n"
		"   .--._ >><.' \\>>>>>>///||  |  |<<>><|.'       )-----'`.\n"
		"   |   _.--'    |///////\\\\\\-----'<>>>>>==\\\\<><>>>>< ===::===>>><****| .'`.`_ (   `-.   .--'\n"
		"  /    .'>><>>)_ -->>>>===::::==>>******|/>>>/  `.  .--.`-.|\n"
		" /    />>>>>>>'`'`'`-`<===:::<<< *****(\\ .-.<(   )-(   )\n"
		"/.'| />>>>>>>.-.-.-._\\|> =//||\\\\******-'@--'>>`-'<<\\`-'`._\n"
		"   |/>>>>>>>-'`'`'`-.\\\\>>==<<<<***.'\\ |_|)_|<<<<<<< \\_ `- `.\n"
		"  / >>>>>>.-..''`'`-.\\\\.->>>><<>(  /(\\\\\\\\\\/// <<<<<=    \\_ .-'\n"
		" /-' >>>----\\((::::)))// /><>>**|   (\\\\\\\\\\///<<<<---.\n"
		"|.'  >>>| | | |\\__.'.'>>>>>****.'/ (\\\\\\\\////<<<<-`-`\n"
		" `   >>>|-|-| |>>>>>>>>>>**** .--. /_\\\\\\\\\\////<<<|_|_|<<<\n"
		"     >>>|_|_|/>><>><<>*****vv(    V  `.\\\\<<<>>>|_|_|<<<<\n"
		"     ////>>>>>`.>>>>******>>><`--'\\   /<<<<<>>>>><<<<<<<\n"
		"     '' ///>>>>><<>>*****>>>><<<<<<`-'<<<<<<>><<<><<<<<<<\n"
		"       ''    ->>>>><<>///>>>>><<<<<<\\\\\\\\\\\\><<<<<>>><<<<\\\\\n"
		"               ////<<>><<<>>>><<<<>\\\\\\\\\\\\\\>><\\\\\\\\\\\\\\\n"
		"              '' / ////////>>><<<\\\\\\\\\\\\\\\\<  \\\\\\ \\\\\\\n"
		"                   /|| .////|||\\\\\\\\\\\\\\\\\n"
		"                      (MMMMMMMMMMMMMMMMMMM)\n"
		"                      |`----.MMMMMMMM.---'|\n"
		"                      `---.____   ____.---'\n"
		"                       |       \"\"\"       |\n"
		"                       |                 |\n"
		"                       |                 |\n"
		"                       |                 |\n"
		"                       |                 |\n"
		"  VK                   (                 )\n"
		"                        `----._____.----'\n";
	outputFile.close();

}