/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2015 Geoffrey Viola <geoffrey.viola@asirobots.com>

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#include "cmLocalGhsMultiGenerator.h"
#include "cmGlobalGhsMultiGenerator.h"
#include "cmGeneratorTarget.h"
#include "cmMakefile.h"
#include "cmGhsMultiTargetGenerator.h"
#include "cmGeneratedFileStream.h"

cmLocalGhsMultiGenerator::cmLocalGhsMultiGenerator(cmGlobalGenerator* gg,
                                                   cmMakefile* mf)
  : cmLocalGenerator(gg, mf)
{
}

cmLocalGhsMultiGenerator::~cmLocalGhsMultiGenerator() {}

void cmLocalGhsMultiGenerator::Generate()
{
  cmGeneratorTargetsType tgts = this->GetGeneratorTargets();

  for (cmGeneratorTargetsType::iterator l = tgts.begin(); l != tgts.end();
       ++l)
    {
    if (l->second->GetType() == cmState::INTERFACE_LIBRARY
        || l->second->IsImported())
      {
      continue;
      }
    cmGhsMultiTargetGenerator tg(l->second);
    tg.Generate();
    }
}
