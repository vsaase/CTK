/*=============================================================================

Library: CTK

Copyright (c) 2010 Brigham and Women's Hospital (BWH) All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

=============================================================================*/

#include "ctkModuleParameterValue.h"

#include <QDebug>

//----------------------------------------------------------------------------
ctkModuleParameterValue::ctkModuleParameterValue( const ctkModuleParameter& param)
: Parameter( param )
{
}

//----------------------------------------------------------------------------
void ctkModuleParameterValue::setValue( const QVariant& val)
{
  value = val;
}

//----------------------------------------------------------------------------
const QVariant& ctkModuleParameterValue::getValue() const
{
  return value;
}

//----------------------------------------------------------------------------
const ctkModuleParameter& ctkModuleParameterValue::parameter() const
{
  return Parameter;
}

void ctkModuleParameterValue::setDefaultValue()
{
  QVariant::Type type = value.type();
  if (type == QVariant::Bool)
    {
      value = (Parameter["Default"].compare("true", Qt::CaseInsensitive) == 0);
    }
  else if (type == QVariant::Int)
    {
      value = Parameter["Default"].toInt();
    }
  else if (type == QVariant::Double)
    {
      value = Parameter["Default"].toDouble();
    }
  else if (type == QVariant::String)
    {
      value = Parameter["Default"];
    }
  else
    {
    qDebug() << "Unknown widget value type:" << type;
    }

}