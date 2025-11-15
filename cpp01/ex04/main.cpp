/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:22:51 by ekeller-          #+#    #+#             */
/*   Updated: 2025/11/15 16:58:55 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

//replace all occurences of s1 for s2 without  std::string::replace.
static std::string replace(const std::string &line, const std::string &s1, const std::string &s2)
{
    std::string result;
    std::string::size_type pos = 0;

    while (true) {
        //searches for the next ocurrence of s1 starting at pos and saves the index at found;
        std::string::size_type found = line.find(s1, pos);
        //if did not find s1, "find" returns npos
        if (found == std::string::npos) {
            result += line.substr(pos);
            break;
        }
        // copies the part just before s1
        result += line.substr(pos, found - pos);
        // add s2
        result += s2;
        // advance pos just after s1
        pos = found + s1.length();
    }
    return result;
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Use: " << argv[0] << " <file> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error while opening file" << std::endl;
        return 1;
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile) {
        std::cerr << "Error while creating output file." << std::endl;
        return 1;
    }

    std::string line;
    bool firstLine = true;
    while (std::getline(infile, line)) {
        // replace replaces s1 in each line
        std::string result = replace(line, s1, s2);

        //does not include \n before the first line
        if (!firstLine)
            outfile << std::endl;
        firstLine = false;

        outfile << result;
    }
    //would be close atomatically
    infile.close();
    outfile.close();

    return 0;
}
