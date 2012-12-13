/*
 * $Id: mfexp.cpp 542 2012-07-10 21:04:06Z johnoel $
 *
 * Author: Hans J. Skaug
 * Copyright (c) 2009-2012 ADMB foundation
 */
/**
  \file tpl2cpp_output.hpp
  Typical output from the preprosessor "tpl2cpp". This file is 
  generated by the command

    tpl2cpp tpl2cpp_output

  in a case case there the model is contained in "tpl2cpp_output.tpl". 
  Hence the contents of tpl2cpp_output.hpp is model specific, 
  and only generic aspects are documented.
  Note: the extention of the file has been changed from ".htp" to ".hpp" 
 */


/**
 * Data structure that holds objects defined in the DATA_SECTION of the tpl-file.
 */
class model_data : public ad_comm{
  data_int n;
  data_matrix Y;
  double y2;
  double penalty;
  ~model_data();
  model_data(int argc,char * argv[]);
  friend class model_parameters;
};

/**
 * Data structure that holds objects defined in the PARAMETER_SECTION of the tpl-file.
 */
class model_parameters : public model_data ,
  public function_minimizer
{
public:
  ~model_parameters();
  void preliminary_calculations(void);
  void set_runtime(void);
  virtual void * mycast(void) {return (void*)this;}
  static int mc_phase(void)
  {
    return initial_params::mc_phase;
  }
  static int mceval_phase(void)
  {
    return initial_params::mceval_phase;
  }
  static int sd_phase(void)
  {
    return initial_params::sd_phase;
  }
  static int current_phase(void)
  {
    return initial_params::current_phase;
  }
  static int last_phase(void)
  {
    return (initial_params::current_phase
      >=initial_params::max_number_phases);
  }
  static prevariable current_feval(void)
  {
    return *objective_function_value::pobjfun;
  }
private:
  ivector integer_control_flags;
  dvector double_control_flags;
  param_init_vector alpha;
  param_init_bounded_vector beta;
  param_init_bounded_number gamma;
  param_number x1;
  param_vector x2;
  param_stddev_vector x3;
  param_number prior_function_value;
  param_number likelihood_function_value;
  objective_function_value l;
  void between_phases_calculations(void);
public:
  virtual void userfunction(void);
  virtual void report(void);
  virtual void final_calcs(void);
  model_parameters(int sz,int argc, char * argv[]);
  virtual void initializationfunction(void);
  void my_function(void);

};
#endif
