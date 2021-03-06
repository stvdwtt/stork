#include "AukApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<AukApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

AukApp::AukApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  AukApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  AukApp::associateSyntax(_syntax, _action_factory);
}

AukApp::~AukApp()
{
}

// External entry point for dynamic application loading
extern "C" void AukApp__registerApps() { AukApp::registerApps(); }
void
AukApp::registerApps()
{
  registerApp(AukApp);
}

// External entry point for dynamic object registration
extern "C" void AukApp__registerObjects(Factory & factory) { AukApp::registerObjects(factory); }
void
AukApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void AukApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { AukApp::associateSyntax(syntax, action_factory); }
void
AukApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
