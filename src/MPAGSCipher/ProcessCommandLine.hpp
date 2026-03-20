#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include "CipherMode.hpp"
#include "CipherType.hpp"

#include <string>
#include <vector>

/**
 * \file ProcessCommandLine.hpp
 * \brief Contains the declarations of the function for processing the command-line arguments and the data structure used to hold the resulting settings
 */

/**
 * \struct ProgramSettings
 * \brief Holds the settings of the program that can be modified by command-line arguments
 */
struct ProgramSettings {
    /// Indicates the presence of the help flag in the arguments
    bool helpRequested{false};
    /// Indicates the presence of the version flag in the arguments
    bool versionRequested{false};
    /// Name of the input file
    std::string inputFile;
    /// Name of the output file
    std::string outputFile;
    /// Key to be used in encrypting/decrypting routine
    std::vector<std::string> cipherKey;
    /// Which cipher(s) to use (e.g. Caesar, Playfair, etc.)
    std::vector<CipherType> cipherType;
    /// Flag indicating the mode in which the cipher should run (i.e. encrypt or decrypt)
    CipherMode cipherMode{CipherMode::Encrypt};
};

/**
 * \class MissingArgument
 * \brief Exception object for missing command-line arguments
 *
 */
class MissingArgument : public std::invalid_argument {
  public:
    /**
     * \brief Construct a MissingArgument exception
     * \param err_message the diagnostic message
     */
    MissingArgument(const std::string& err_message) : std::invalid_argument(err_message) {}
};

class InvalidArgument : public std::invalid_argument {
  public:
    /**
     * \brief Construct an InvalidArgument exception
     * \param err_message the diagnostic message
     */
    InvalidArgument(const std::string& err_message) : std::invalid_argument(err_message) {}
};

class UnknownArgument : public std::invalid_argument {
  public:
    /**
     * \brief Construct an UnknownArgument exception
     * \param err_message the diagnostic message
     */
    UnknownArgument(const std::string& err_message) : std::invalid_argument(err_message) {}
};

class ConflictingArgument : public std::invalid_argument {
  public:
    /**
     * \brief Construct a ConflictingArgument exception
     * \param err_message the diagnostic message
     */
    ConflictingArgument(const std::string& err_message) : std::invalid_argument(err_message) {}
};

/**
 * \brief Processes the command-line arguments and modifies accordingly the program settings
 *
 * \param cmdLineArgs The command-line arguments to be processed
 * \param settings The program settings to be set according to the result of the processing
 * \return true if the arguments could be successfully parsed, false otherwise
 */
bool processCommandLine(const std::vector<std::string>& cmdLineArgs,
                        ProgramSettings& settings);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
