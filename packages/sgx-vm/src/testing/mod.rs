// The external interface is `use cosmwasm_vm::testing::X` for all integration testing symbols, no matter where they live internally.

mod calls;
mod instance;
mod mock;
mod querier;
mod storage;

pub use calls::{handle, init, migrate, query};
pub use instance::{
    mock_instance, mock_instance_with_balances, mock_instance_with_failing_api,
    mock_instance_with_gas_limit, mock_instance_with_options, MockInstanceOptions,
};
pub use mock::{
    mock_dependencies, mock_dependencies_with_balances, mock_env, MockApi, MOCK_CONTRACT_ADDR,
};
pub use querier::MockQuerier;
#[cfg(feature = "iterator")]
pub use storage::MockIterator;
pub use storage::MockStorage;
