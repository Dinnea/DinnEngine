#pragma once
namespace Dinn
{
    class GameObject;

   class DINN_API Scene
    {
    public:
        Scene();
        virtual ~Scene();
        explicit Scene(std::string SceneName);
       
       Scene(const Scene&) = delete;
       Scene& operator=(const Scene&) = delete;
        
        void StartFrame();
        void Update(float deltaTime);
        void EndFrame();
       
        virtual void OnStartFrame() {} 
        virtual void OnUpdate(float deltaTime){}
        virtual void OnEndFrame(){}
        
        std::string name = "Scene";
        
        GameObject& CreateGameObject();
       
       /// <summary>
       /// Marks a game object for destroying at the end of the frame.
       /// </summary>
       void Destroy(GameObject& gameObject);
        
    private:
       void ExeDestroyObjects();
       
        std::unordered_map<unsigned int, std::unique_ptr<GameObject>> gameObjects;
        std::vector<unsigned int> destroyQueue;
        
        //unsigned int id = 0;
    };
}

