#include "DiamondTrap.hpp"

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n--- Creating DiamondTrap ---\n" << std::endl;
    DiamondTrap dia("DiamondOne");

    std::cout << "\n--- Testing whoAmI() ---\n" << std::endl;
    dia.whoAmI(); // Esperado: exibe "I am DiamondOne, and my ClapTrap name is DiamondOne_clap_name."

    std::cout << "\n--- Testing attack() ---\n" << std::endl;
    dia.attack("TargetBot"); 
    // Esperado: imprime o ataque usando o método da ScavTrap (override do attack com mensagem específica)

    std::cout << "\n--- Testing takeDamage() ---\n" << std::endl;
    dia.takeDamage(30);
    // Esperado: Reduz hitPoints e imprime mensagem de dano

    std::cout << "\n--- Testing beRepaired() ---\n" << std::endl;
    dia.beRepaired(20);
    // Esperado: Aumenta hitPoints e imprime mensagem de reparo

    std::cout << "\n--- Testing guardGate() (ScavTrap) ---\n" << std::endl;
    dia.guardGate(); 
    // Esperado: imprime que entrou em modo Gate keeper

    std::cout << "\n--- Testing highFivesGuys() (FragTrap) ---\n" << std::endl;
    dia.highFivesGuys(); 
    // Esperado: imprime mensagem positiva pedindo high five

    std::cout << "\n--- Copy Constructor Test ---\n" << std::endl;
    DiamondTrap diaCopy(dia);
    diaCopy.whoAmI(); // Esperado: cópia correta dos nomes

    std::cout << "\n--- Assignment Operator Test ---\n" << std::endl;
    DiamondTrap diaAssign;
    diaAssign = dia;
    diaAssign.whoAmI(); // Esperado: mesma saída que dia

    std::cout << "\n--- Destructor Call Sequence (automatic on return) ---\n" << std::endl;
    return 0;
}
