#ifndef INSTRUCTIONCOUNTANNOTATOR_H
#define INSTRUCTIONCOUNTANNOTATOR_H


class SgNode;

#include <vector>
#include <string>

/**
 * \brief Annotates each SgAsmInstruction which its execution count using data from IntelPIN
 */
namespace InstructionCountAnnotator
{

  /** Annotates each SgAsmInstruction with a number
   *  indicating how often this instruction was executed
   *
   *  the needed pin tool which generates this file can be found in  util/pin/my_itrace.cpp
   *
   * @param proj the (binary) SgProject to annotate
   * @param instfile path of file with pairs of address - execCount
   *                 format "addressInHex \t count \n"
   *                 can for example be generated by intel-pin
   */
    void annotate(SgNode * proj, const std::string & instfile);



    /** Annotates each SgAsmInstruction with a number
     *  indicating how often this instruction was executed
     *
     * @param proj the (binary) SgProject to annotate
     * @param args array with parameters for the process to trace
     *             (only parameter i.e. args[0] is NOT the exec name
     */
    void annotate(SgNode * proj, std::vector<std::string> args);

};


#endif

