#pragma once

namespace Leaf {

class Layer {
  public:
    Layer()          = default;
    virtual ~Layer() = default;

    virtual void onAttach() {}
    virtual void onDetach() {}
    virtual void onUIRender() {}
};

}
