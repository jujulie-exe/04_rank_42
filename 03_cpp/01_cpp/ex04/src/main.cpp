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

std::string replaceAll(std::string const& input,
                       std::string const& from,
                       std::string const& to)
{
    std::string result;
    size_t start = 0;
    size_t pos;

    while ((pos = input.find(from, start)) != std::string::npos) 
	{
        result.append(input, start, pos - start);
        result += to;
        start = pos + from.length();
    }

    result.append(input, start, input.size() - start);
    return result;
}

int	error(int flags)
{
	if (flags == 0)
		std::cerr << "Error opening input file!" << std::endl;
	else if (flags == 1)
		std::cerr << "Error: Incorrect number of arguments. Syntax: program <file> <search_word> <replace_word>" << std::endl;
	else if (flags == 2)
		std::cerr << "Error opening output file! or EOF in input file" << std::endl;
	return -1;
}

int	main(int argc, char **argv)
{
	std::string word;

	if (argc == 4 && !std::string(argv[1]).empty() && !std::string(argv[2]).empty() && !std::string(argv[3]).empty())
	{
		std::ifstream FileData(argv[1]);
		if (!FileData)
			return (error(0));
		std::string filename = std::string(argv[1]) + ".replace";
		std::ofstream OutFile(filename.c_str());
		FileData.peek();
		if(!OutFile || FileData.eof())
		{
			FileData.close();
			return (error(2));
		}
		std::string	result;
		while (std::getline(FileData, word))
		{
				result += replaceAll(word, std::string(argv[2]), std::string(argv[3]));
				result += "\n";
		}
		OutFile << result;
		OutFile.close();
		FileData.close();
	}
	else
		return (error(1));
	return (0);
}
