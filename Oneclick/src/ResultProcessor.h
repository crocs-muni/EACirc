#ifndef RESULTPROCESSOR_H
#define RESULTPROCESSOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <regex>
#include <iostream>
#include <iomanip>

#include "FileSystem.h"
#include "OneclickConstants.h"

/** Class for storing result of single batch.
  */
class Score {
private:
	std::string algName;
	float val;
public:
	/** Sets attribute algName.
	  * @param a	will be algName
	  */
	void setAlgName(std::string a) { algName = a; }

	/** Sets attribute val.
	  * @param s	will be val
	  */
	void setVal(float s) { val = s; }

	/** Returns formatted string, contains algname    val.
	  * @return formatted result
	  */
	std::string toString() {
		std::stringstream result;
		result << std::setw(30);
		result << std::left;
		result << algName;

		result << std::setprecision(6);
		result << std::setw(15);
		result << std::right;
		if(val == ERROR_NO_VALID_FILES) {
			result << "no valid logs";
		} else {
			result << val;
		}
		return result.str();
    }
};

class ResultProcessor {
private:
	std::vector<Score> scores;
public:
	/** Constructor for ResultProcessor class.
	  * Checks given directory for config and log errors.
	  * If directory is valid, processes its results and writes them into file.
	  * @paran path				path to directory with results
	  *							(one directory per batch)
	  * @throw runtime_error	if invalid directory was given
	  */
	ResultProcessor(std::string path);
private:
	/** Checks config files on given paths for differences.
	  * @param configPaths		vector of paths to be checked
	  * @param algName			empty string, algorithm name will be set into it
	  * @param dirLogger		batch specific logger, logs different configs
	  * @return					true if all configs are same, false otherwise
	  */
	bool checkConfigs(std::vector<std::string> configPaths , std::string & algName , FileLogger * dirLogger);

	/** Checks logs on given paths for errors and warnings.
	  *	If log has no errors, results from log are processed and pValue is stored.
	  * @param logPaths			paths to logs to process
	  * @param pValues			string to store pValues from logs with no errors
	  * @dirLogger				logs batch specifis events =
	  *							= errors, warnings, missing results, 
	  *							inconsistent results, too many results
	  * @return result			0-1 => uniformLogs/validLogs, if validLogs = 0
	  *							returns error constant (ERROR_NO_VALID_FILES)
	  */
	float checkErrorsGetScore(std::vector<std::string> logPaths , std::string & pValues , FileLogger * dirLogger);

	/** Recursively searches given directory,
	  * stores paths to files with given index.
	  * @param directory		directory to search in
	  * @param paths			paths to files
	  * @param fileIndex		file indexes to look for
	  * @throws runtime_error	if given argument is not a directory
	  */
	void getFilePaths(std::string directory , std::vector<std::string> & paths , int fileIndex);

	/** Writes scores for all batches into .txt file FILE_PROCESSED_RESULTS
	  * @throws runtime_error	when output file can't be opened
	  */
	void writeScores();

	/** Parses filename and gets index at the end.
	  * Index is separated by "_". Returns -1 if no
	  * index is found
	  * @param fileName			name of the file
	  * @return index
	  */
	int getFileIndex(std::string fileName);

	/** Retrieve tag <NOTES> from config file.
	  * @param config			config file loaded into string
	  * @return					string with notes
	  */
	std::string getNotes(std::string config);
};

#endif //RESULTPROCESSOR_H
