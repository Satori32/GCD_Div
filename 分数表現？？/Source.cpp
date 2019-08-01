#include <iostream>
#include <cstdint>
#include <numeric>
#include <tuple>
#include <string>
#include <random>

std::tuple<std::intmax_t, std::intmax_t> GetInput() {

	std::intmax_t A = 0;
	std::intmax_t B = 0;

	std::cout << "?/X" << std::endl;
	std::cin >> A;
	std::cout << A <<"/?" << std::endl;	
	std::cin >> B;
	return { A,B };

}

std::tuple<std::intmax_t,std::intmax_t> MakeHoge(std::intmax_t A, std::intmax_t B) {

	std::intmax_t C = 0;

	do {
		C = std::gcd(A, B);
		A /= C;
		B /= C;
	} while (C != 1);

	return {A,B};
}

int main() {

	std::cout << "Š„‚èŽZ‚Ì•ª”•\Œ»" << std::endl;

	//auto [A, B] = GetInput();


	std::random_device rd;
	std::mt19937 mt(rd());
	//std::minstd_rand mr(rd());
	std::uniform_int_distribution<>  UI(2, 1024);

	for (std::size_t i = 0; i < 128; i++) {
		//auto A = UI(mr);
		//auto B = UI(mr);
		auto A = UI(mt);
		auto B = UI(mt);
		auto [C, D] = MakeHoge(A, B);
		std::cout <<A<<','<<B<<':'<< " \tit's[" << C << '/' << D << "]\t[" <<C/static_cast<double>(D)<<"]"<< std::endl;
	}

	return 0;

}