/*
   Copyright (C) 2013  Statoil ASA, Norway. 
    
   The file 'enkf_ensemble_GEN_PARAM.c' is part of ERT - Ensemble based Reservoir Tool. 
    
   ERT is free software: you can redistribute it and/or modify 
   it under the terms of the GNU General Public License as published by 
   the Free Software Foundation, either version 3 of the License, or 
   (at your option) any later version. 
    
   ERT is distributed in the hope that it will be useful, but WITHOUT ANY 
   WARRANTY; without even the implied warranty of MERCHANTABILITY or 
   FITNESS FOR A PARTICULAR PURPOSE.   
    
   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html> 
   for more details. 
*/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include <ert/util/test_util.h>
#include <ert/util/util.h>
#include <ert/util/thread_pool.h>
#include <ert/util/arg_pack.h>

#include <ert/config/config.h>

#include <ert/ecl/ecl_sum.h>

#include <ert/enkf/ensemble_config.h>
#include <ert/enkf/time_map.h>







int main(int argc , char ** argv) {
  const char * config_file = argv[1];
  config_type * config = config_alloc();
  ensemble_config_type * ensemble = ensemble_config_alloc();

  enkf_config_node_add_GEN_PARAM_config_schema( config );
  test_assert_true( config_parse( config , config_file , "--" , NULL , NULL , CONFIG_UNRECOGNIZED_WARN , true ) );

  ensemble_config_init_GEN_PARAM( ensemble, config );
  
  config_free( config );
  ensemble_config_free( ensemble );
  exit(0);
}

