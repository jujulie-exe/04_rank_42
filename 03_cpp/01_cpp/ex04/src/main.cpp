/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:32:18 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/05 17:34:53 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fstream>
#include <ostream>
#include <iostream>

std::string	add_space(std::ifstream *Data, size_t *n)
{
	std::string word;
	char	ch;

	while (Data->get(ch))
	{
		if ((ch != ' ' && ch != '	' && ch != '\n'))
			break ;
		word += ch;
		(*n)++;
	}
	Data->unget();
	return (word);

}

int	error(int flags)
{
	if (flags == 0)
		std::cerr << "Error opening input file!" << std::endl;
	else if (flags == 1)
		std::cerr << " Error: Incorrect number of arguments. Syntax: program <file> <search_word> <replace_word>" << std::endl;
	else if (flags == 2)
		std::cerr << "Error: you can search ad empty word" << std::endl;
	return -1;
}

void	trim(std::string& str)
{
	str.erase(0, str.find_first_not_of(" 	"));
	str.erase(str.find_last_not_of(" 	") + 1);
}

int	main(int argc, char **argv)
{
	size_t	n = 0;
	char	ch;
	std::string word;

	if (argc == 4 && !std::string(argv[1]).empty() && !std::string(argv[2]).empty() && !std::string(argv[3]).empty())
	{
		std::ifstream FileData(argv[1]);
		if (!FileData)
			return (error(0));
		std::string filename = std::string(argv[1]) + ".replace";
		std::ofstream OutFile(filename.c_str());
		FileData.get(ch);
		std::string arg_trimmed = argv[2];
		trim(arg_trimmed);
		if (arg_trimmed.empty())
			return (error(2));
		std::cout << arg_trimmed;
		if (std::isspace(ch) || ch == '\n')
		{
			word = add_space(&FileData, &n);
			OutFile << word;
		}
		FileData.seekg(0);
		while (FileData >> word)
		{
			if (word == arg_trimmed)
				word = argv[3];
			word += add_space(&FileData, &n);
			OutFile << word;
		}
	}
	else
		return (error(1));
	return (0);
}
