#
# Strelka - Small Variant Caller
# Copyright (c) 2009-2016 Illumina, Inc.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#

################################################################################
##
## file CMakeLists.txt
##
################################################################################

include ("${THIS_GLOBALS_CMAKE}")

set (THIS_STRELKADEMODIR "${THIS_DEMODIR}/strelka")
install(FILES "README.md" DESTINATION ${THIS_STRELKADEMODIR})
install(DIRECTORY "expectedResults" DESTINATION ${THIS_STRELKADEMODIR})
#install(DIRECTORY "expectedResultsMito" DESTINATION ${THIS_STRELKADEMODIR})

install(FILES runStrelkaGermlineWorkflowDemo.bash  DESTINATION ${THIS_BINDIR} PERMISSIONS ${THIS_EXECUTABLE_PERMISSIONS})
install(FILES runStrelkaSomaticWorkflowDemo.bash  DESTINATION ${THIS_BINDIR} PERMISSIONS ${THIS_EXECUTABLE_PERMISSIONS})
install(FILES runMitoWorkflowDemo.bash  DESTINATION ${THIS_LIBEXECDIR} PERMISSIONS ${THIS_EXECUTABLE_PERMISSIONS})
#install(FILES "runDenovoVariantWorkflowDemo.bash"  DESTINATION ${THIS_BINDIR} PERMISSIONS ${THIS_EXECUTABLE_PERMISSIONS})

# add legacy filename links
install(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" -E create_symlink runStrelkaGermlineWorkflowDemo.bash runStarlingWorkflowDemo.bash WORKING_DIRECTORY ${THIS_BINDIR})")
install(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" -E create_symlink runStrelkaSomaticWorkflowDemo.bash runStrelkaWorkflowDemo.bash WORKING_DIRECTORY ${THIS_BINDIR})")

add_subdirectory (data)

