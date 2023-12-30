#include "Maquina.h"
#include "Casino.h"


//Cria uma maquina com dados passados neste caso são os dados do ficheiro xml
Maquina::Maquina(string id, int probabilidadeGanhar, int premio, int x, int y, int tempAviso)
{
    ID = id;
    WINRATE = probabilidadeGanhar;
    PREMIO = premio;
    X = x;
    Y = y;
    TEMPAVISO = tempAviso;

}

// destruidor de uma maquina (mas tambem é feita no ficheiro casino)
Maquina::~Maquina()
{
    cout << "Maquina: " << ID << "destruida" << endl;
}

//Devolve o tipo de uma maquina
string Maquina::GetTipo() const {
    return Tipo;
}

//Função escolhe uma pessoa e uma maquina ao calhas, mostra as informações sobre os dois e junta-os dentro de uma função jogobase para serem usados no final a maquina que foi escolhida aleatoriamente ainda tem chance de ficar estragada caso isso aconteça entra na lista de maquinas estragadas
void Maquina::Escolheramalta()
{
   int numeroAleatorio = std::rand() % 100 + 1;
   Casino meuCasino("Casino Figueira");
   Maquina minhamaquina("TempID",0,0,0,0,0);
   cout << "Jogador Aleatório Escolhido:\n";
   Jogador* jogadorAleatorio = meuCasino.EscolherJogadorAleatorio();
   Maquina* maquinaaleatoria = meuCasino.EscolherMaquinaAleatoria();
   jogadorAleatorio->Show_Jogador();
   maquinaaleatoria->Show_maquina();
   maquinaaleatoria->Jogobase(jogadorAleatorio, maquinaaleatoria->getWinRate());
    int estragado = 5;
    float numeroestragado = (rand() % 31);
    if (numeroestragado >= estragado) {
            meuCasino.AdicionarMaquinaAvariada(maquinaaleatoria);
            cout << "ATENÇÃO A MAQUINA: " << maquinaaleatoria << "ESTÁ ESTRAGADA E NAO PODE SER UTILIZADA" << endl;
        }
}

//função que recebe um jogador e uma maquina e calcula caso tenha ganho ou nao
void Maquina::Jogobase(Jogador* jogador, float winRate)
{

    float numeroJogador = (rand() % 11) * winRate; // Escolhe um número aleatório de 0 a 10 para o jogador e multiplica pela winRate
    float numeroRoleta = 7;

    if (numeroJogador >= numeroRoleta) {
        cout << "Parabéns! Você venceu!" << endl;
    } else {
        cout << "Você perdeu! Você está expulso !------------------------------------------" << endl;
    }
}

//Mostra toda a informação de uma maquina
void Maquina::Show_maquina() {
    cout << "Nome da Máquina: " << ID << std::endl;
    cout << "Probabilidade de Ganhar: " << WINRATE << std::endl;
    cout << "Prêmio: " << PREMIO << std::endl;
    cout << "Coordenadas (x, y): " << X << ", " << Y << std::endl;
    cout << "Temperatura de Aviso: " << TEMPAVISO << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//criação da maquina do tipo roleta
Roleta::Roleta(string id, int probabilidadeGanhar, int premio, int x, int y, int tempAviso)
: Maquina(id, probabilidadeGanhar, premio, x, y, tempAviso)
{

}

Roleta::~Roleta() {
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//criação da maquina do tipo classicSlots
ClassicSlots::ClassicSlots(string id, int probabilidadeGanhar, int premio, int x, int y, int tempAviso)
: Maquina(id, probabilidadeGanhar, premio, x, y, tempAviso)
{

}

ClassicSlots::~ClassicSlots() {
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//criação da maquina do tipo slots_tematicos
Slots_tematicos::Slots_tematicos(string id, int probabilidadeGanhar, int premio, int x, int y, int tempAviso)
: Maquina(id, probabilidadeGanhar, premio, x, y, tempAviso)
{

}

Slots_tematicos::~Slots_tematicos() {
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//criação da maquina do tipo blackjack
Blackjack::Blackjack(string id, int probabilidadeGanhar, int premio, int x, int y, int tempAviso)
: Maquina(id, probabilidadeGanhar, premio, x, y, tempAviso)
{

}

Blackjack::~Blackjack() {
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//criação da maquina do tipo variantes_poker
Variantes_Poker::Variantes_Poker(string id, int probabilidadeGanhar, int premio, int x, int y, int tempAviso)
: Maquina(id, probabilidadeGanhar, premio, x, y, tempAviso)
{


}

Variantes_Poker::~Variantes_Poker() {
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//criação da maquina do tipo slots de recursos
Slots_de_recursos::Slots_de_recursos(string id, int probabilidadeGanhar, int premio, int x, int y, int tempAviso)
: Maquina(id, probabilidadeGanhar, premio, x, y, tempAviso)
{


}

Slots_de_recursos::~Slots_de_recursos() {
}




